from subprocess import call

def runtests(cmds):
    print('Testing {}'.format(cmds[0][-1]))
    for cmd in cmds:
        call(cmd)

if __name__ == '__main__':
    cmds = [['cxxtestgen', '--error-printer', '-o', 'runner.cpp', 'bst_tests.h'], ['g++', '-o',
'runner', 'runner.cpp', '-std=c++11'], ['./runner']]
    runtests(cmds)
    cmds[0][-1] = 'rbt_tests.h'
    runtests(cmds)
