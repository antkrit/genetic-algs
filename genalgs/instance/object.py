"""Contains genetic algorithm instance definition."""
from genalgs.instance import _ga_instance as instance_api


__all__ = ["instance"]


class instance(instance_api.GABaseInstance):
    """Genetic Algorithm instance."""
    
    def __repr__(self):
        return f'instance(value={self.value}, score={self.score})'


if __name__ == "__main__":
    inst = instance(score=0.2, value="asd")
    print(inst.get_score())
    print(inst)
