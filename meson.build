project(
    'Genetic-Algorithms',
    'c',
    version: run_command(
        ['python', 'ga_core/_build_utils/version.py'],
        check: true
    ).stdout().strip(),
)

py = import('python').find_installation(pure: false)
ga_dir = py.get_install_dir() / 'ga_core'

if py.language_version().version_compare('<3.9')
    error('At least Python 3.9 is required.')
endif
py_dep = py.dependency()

subdir('ga_core')
