class Course:
    def __init__(self, program: str, name: str) -> None:
        self.name: str = name
        self.program: str = program
        self.student_count: int = 0
        self.student_interest: float = 0.5
        self.student_capacity: int = 0
        self.teacher_count: int = 0
        self._prestige: int = 50

    def __repr__(self) -> str:
        return (f"Course instance (Name={self.name}, Program={self.program})")

    def __str__(self) -> str:
        return (f"Course {self.name}, Program {self.program}")
