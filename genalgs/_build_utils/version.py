import os


def read_from_pyproject():
    ptoml = os.path.join(os.path.dirname(__file__), '../../pyproject.toml')
    with open(ptoml) as fid:
        data = fid.readlines()

    version_line = next(
        line for line in data if line.startswith('version =')
    )

    version = version_line.strip().split(' = ')[1]
    version = version.replace('"', '').replace("'", '')

    return version


if __name__ == "__main__":
    import argparse

    parser = argparse.ArgumentParser()
    args = parser.parse_args()

    version = read_from_pyproject()
    print(version)
