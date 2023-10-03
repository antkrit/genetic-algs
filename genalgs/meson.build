# build current directory
python_sources = files([
    '__init__.py',
    'generic.py',
    'score.py',
    'types.py',
])

py.install_sources(
    python_sources,
    subdir: 'genalgs'
)


# build subdirs without meson.build file
pure_subdirs = [
    '_build_utils',
    'instance',
    'operations'
]

foreach subdir: pure_subdirs
    install_subdir(subdir, install_dir: ga_dir)
endforeach


# build `genalgs.instance._ga_instance` extension
py.extension_module('_ga_instance',
    [
        'instance/object.c',
    ],
    install: true,
    subdir: 'genalgs/instance'
)


# build `genalgs.operations._ga_operations` extension
py.extension_module('_ga_operations',
    [
        'operations/_list_utils.c',
        'operations/sorting.c',
        'operations/operations.c',
    ],
    install: true,
    subdir: 'genalgs/operations'
)


# build subdirs with meson.build file
subdir('include')
