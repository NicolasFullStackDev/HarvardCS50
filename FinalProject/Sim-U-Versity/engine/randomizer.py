import random
from engine.dataset import FIRST_NAME, LAST_NAME

def randomize_name(gender: str) -> None:
    name = f'{random.choice(FIRST_NAME[gender])} {random.choice(LAST_NAME)}'
    return name
