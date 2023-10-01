project('genetic-algs', 'c')

py = import('python').find_installation(pure: false)

inc = include_directories('ga_core/operations/include')
ga_sources = files([
    'ga_core/operations/_list_utils.c',
    'ga_core/operations/_sorting.c',
    'ga_core/operations/operations.c'
])

ga_core = py.extension_module(
    'operations',
    ga_sources,
    include_directories : inc,
    install : true
)

# pkg_mod = import('pkgconfig')
# pkg_mod.generate(
#     libraries : ga_core,
#     version : '0.1.0',
#     name : 'genetic_algs',
#     filebase : 'ga_core',
#     description : 'A library with generic genetic algortm\'s objects.'
# )
