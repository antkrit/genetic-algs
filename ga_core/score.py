from ga_core.types import _SCORE_OBJ_TYPE


class Estimator:

    def __init__(self, objective: _SCORE_OBJ_TYPE):
        self.objective = objective

    def __call__(self, population: list) -> list[float]:
        return self.objective(population)
