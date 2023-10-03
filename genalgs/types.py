class string(str):
    """Convert value to supported string type."""
    def __call__(self, value):
        return str(value)


class numeric(float):
    """Convert value to supported numeric type."""
    def __call__(self, value):
        return float(value)


_GAI_TYPES = None
_SCORE_OBJ_TYPE = None
