python_sources = files([
    '__init__.py',
    'generic.py',
    'score.py',
    'types.py',
])

py.install_sources(
    python_sources,
    subdir: 'ga_core'
)

pure_subdirs = [
    'include',
    'operations'
]

foreach subdir: pure_subdirs
    install_subdir(subdir, install_dir: ga_dir)
endforeach

ga_operations_sources = files([
    'operations/_list_utils.c',
    'operations/_sorting.c',
    'operations/operations.c',
])

py.extension_module(
    '_ga_operations',
    ga_operations_sources,
    install: true,
    subdir: 'ga_core/operations'
)

subdir('include')
