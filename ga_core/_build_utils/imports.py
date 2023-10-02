def get_module_methods(module):
    """Returns methods from module if __all__ is not defined."""
    return (
        (x for x in dir(module) if not x.startswith('_'))
        if not hasattr(module, '__all__')
        else module.__all__.copy()
    )