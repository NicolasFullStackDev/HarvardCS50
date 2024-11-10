from Simuversity.engine.academics import Course
from engine.facilities import Facility
from engine.students import Student
from engine.teachers import Teacher

class University:
    def __init__(self, name: str) -> None:
        """
        Initialize a new University with given name.
        This SuperClass is shared between Player and CPU Universities
        """
        self.name: str = name  # The name of the university
        self._prestige: float = 0.0  # Hidden prestige attribute, used for internal purposes
        self.academics: float = 0.0  # Academic score, influenced by programs, teachers, etc.
        self.athletics: float = 0.0  # Athletics score, influenced by teams, scholarships, etc.
        self.campus: float = 0.0  # Campus score, influenced by infrastructure and student facilities


class PlayerUniversity(University):
    """
    Extended University class for the player
    """
    def __init__(self, name: str) -> None:
        super().__init__(name)
        self.courses: list[Course] = []
        self.facilities: list[Facility] = []
        self.students: list[Student] = []
        self.teachers: list[Teacher] = []

