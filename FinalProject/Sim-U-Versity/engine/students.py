from engine.core import Person


class Student(Person):
    def __init__(
            self,
            first_name: str,
            last_name: str,
            academic_index: int,
            atheletic_index: int,
            potential: int,
            age: str) -> None:
        super().__init__(first_name, last_name, academic_index, atheletic_index, potential, age)