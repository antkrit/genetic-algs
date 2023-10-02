from genalgs.operations import _ga_operations as ga_ops


__all__ = ['sort',]


def sort(instances: list, method: str, *args, **kwargs):
    """Sorting interface.
    
    :param instances: list of instances to sort
    :param method: sorting method. One of [`bubble`, `select`]
    """
    sorting_callback = getattr(ga_ops, f"{method}_sort", None)
    if sorting_callback is None:
        raise ValueError(f"Unknown sorting method `{method}`.")

    return sorting_callback(instances, *args, **kwargs)
