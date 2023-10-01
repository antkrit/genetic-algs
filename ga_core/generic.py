from collections.abc import Callable
from ga_core.types import _GAI_TYPES


class Population(list):
    def __init__(
            self,
            n: int,
            gai_generator: Callable[..., _GAI_TYPES],
            gai_type: _GAI_TYPES
    ):
        super(Population, self).__init__([])
        self.gai_type = gai_type
        self.gai_generator = gai_generator
        self.spawn(n)

    def spawn(self, n):
        """Generate random population."""
        self.extend([
            self.gai_type(self.gai_generator())
            for _ in range(n)
        ])
        return self


if __name__ == "__main__":
    pass
