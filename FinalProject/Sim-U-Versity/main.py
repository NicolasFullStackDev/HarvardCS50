from engine.core import Person
from engine.randomizer import randomize_name
from engine.dataset import COURSES
from engine.academics import Course

# Randomize name
print(randomize_name("F"))


# Create all courses
university_courses = []
for course in COURSES:
    new_course = Course(program=course['program'],name=course['name'])
    university_courses.append(new_course)

print(university_courses)