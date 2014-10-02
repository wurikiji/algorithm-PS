#!/usr/bin/python
# -*- coding: utf-8 -*-
# Algospot Online Judge Command-line interface
# Author: Junseong Lee <hodduc@sparcs.kaist.ac.kr>
# Created: 2013-03-01

# -- Imports
import os
import re
import argparse
import urllib
import urllib2
import getpass
import unicodedata
from cookielib import MozillaCookieJar

# -- Globals
SITE_PREFIX = 'http://algospot.com/'
LOGIN_URL = SITE_PREFIX + 'accounts/login/'
PROB_PREFIX = SITE_PREFIX + 'judge/problem/'
REGEXP_CSRF = re.compile(r"name='csrfmiddlewaretoken' value='([a-zA-Z0-9]+)'")
LANGUAGES = ('java', 'scala', 'hs', 'py', 'js', 'rb', 'cpp')

# -- Exceptions
class AOJProblemNotExist(Exception):
    pass
class AOJFileNotExist(Exception):
    pass
class AOJForbidden(Exception):
    pass

# -- Classes
class AOJClient(object):
    def __init__(self, cookie_file_path='aoj-cookie.txt'):
        self.cookie_file_path = cookie_file_path
        self.cookiejar = MozillaCookieJar()
        if os.path.isfile(cookie_file_path):
            self.cookiejar.load(cookie_file_path)

        self.opener = urllib2.build_opener(
                urllib2.HTTPRedirectHandler(),
                urllib2.HTTPHandler(),
                urllib2.HTTPSHandler(),
                urllib2.HTTPCookieProcessor(self.cookiejar))

    def get_csrf_token(self, url):
        request = urllib2.Request(url=url)
        response = self.opener.open(request)
        data = response.read()
        return REGEXP_CSRF.findall(data)[0]

    def refresh_session(self):
        print 'Not Logged In!'
        context = {'csrfmiddlewaretoken': self.get_csrf_token(LOGIN_URL),
                   'username': raw_input('Username: '), 'password': getpass.getpass('Password: ')}

        request = urllib2.Request(url=SITE_PREFIX+'accounts/login/',
                                  data=urllib.urlencode(context))
        self.opener.open(request)
        self.cookiejar.save(self.cookie_file_path)

    def check_problem_exist(self, problem_name):
        try:
            request = urllib2.Request(url=PROB_PREFIX+'read/'+problem_name)
            response = self.opener.open(request)
        except urllib2.HTTPError as err:
            if err.code == 404: # Not Found
                raise AOJProblemNotExist
            else:
                raise

    def detect_language(self, source_file):
        if '.' in source_file:
            selected_language = source_file[source_file.rfind('.')+1:]
        else:
            selected_language = ''
        
        while selected_language not in LANGUAGES:
            selected_language = raw_input('Please select your langauge: (' + '/'.join(LANGUAGES) + ') ? ').strip().lower()

        return selected_language

    def submit(self, submission):
        self.check_problem_exist(submission.problem)
        context = {}
        context['language'] = self.detect_language(submission.source)
        context['csrfmiddlewaretoken'] = self.get_csrf_token(url=PROB_PREFIX+'submit/'+submission.problem)

        try:
            with open(submission.source) as f:
                context['source'] = f.read()
        except IOError:
            raise AOJFileNotExist()

        def try_submit(first=True):
            if not first:
                self.refresh_session()
            request = urllib2.Request(url=PROB_PREFIX+'submit/'+submission.problem,
                                  data=urllib.urlencode(context))
            response = self.opener.open(request)

            if not response.geturl().lower().startswith(LOGIN_URL):
                print 'Submission Complete!'
                return
            try_submit(first=False)
        try_submit()

    def get_submission_list(self, problem_name):
        self.check_problem_exist(problem_name)
        request = urllib2.Request(url=SITE_PREFIX+'judge/submission/recent/?problem='+problem_name)
        response = self.opener.open(request)

        try:
            import lxml.html
        except ImportError:
            print 'lxml library is needed for parsing HTML'
            return

        html = lxml.html.fromstring(unicode(response.read().decode('utf8')))
        context = {}
        fields = ('id', 'problem', 'user', 'language', 'length', 'state', 'stats', 'submitted_on')
        length = {'id': 9, 'problem': 15, 'user': 15, 'language': 5, 'length': 7, 'state': 15, 'stats': 7, 'submitted_on': 15}
        template = u'%(id)s %(problem)s %(user)s %(language)s %(length)s %(state)s %(stats)s %(submitted_on)s'

        def width(string):
            return sum(1+(unicodedata.east_asian_width(c) in 'WF') for c in string)

        for tr in html.cssselect('table.submission_list tr'):
            for field in fields:
                element = tr.find_class(field)
                if element:
                    context[field] = unicode(element[0].text_content().strip())
                else:
                    context[field] = u''
                context[field] = ' ' * (length[field] - width(context[field])) + context[field]
            print template % context

class AOJSubmission(object):
    def __init__(self, problem, source):
        self.problem = problem.upper()
        self.source = source

# -- main
if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='AOJ-Cli: Command line interface for Algospot Online Judge (http://www.algospot.com)')
    parser.add_argument('problem', metavar='PROBNAME', type=str, nargs=1, help='name of the problem')
    parser.add_argument('source', type=str, nargs='?', help='filename to submit')

    args = parser.parse_args()
    client = AOJClient()
    if args.source:
        submission = AOJSubmission(args.problem[0], args.source)
        client.submit(submission)
    else:
        client.get_submission_list(args.problem[0].upper())
