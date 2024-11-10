class Person:
    def __init__(
            self,
            first_name: str,
            last_name: str,
            age: int,
            gender: str,
            academic_index: float,
            atheletic_index: float,
            _potential: float,
            ) -> None:
        self.first_name: str = first_name
        self.last_name: str = last_name
        self.age: int = age
        self.gender: str = gender
        self.academic_index: float = academic_index
        self.athletic_index: float = atheletic_index
        self._potential: float = _potential
        
        def add_age(self) -> None:
            self.age += 1

