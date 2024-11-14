from django.db import models

class WorldSetting(models.Model):
    description = models.CharField(max_length=50, unique=True, null=False)

    def __str__(self):
        return self.description


class World(models.Model):
    name = models.CharField(max_length=255, unique=True, null=False)
    setting = models.ForeignKey(WorldSetting, on_delete=models.PROTECT, null=False)
    created = models.DateTimeField(auto_now_add=True)
    updated = models.DateTimeField(auto_now=True)
    tags = models.ManyToManyField(Tag, related_name="worlds", blank=True)

    def __str__(self):
        return self.name


class BookTrilogy(models.Model):
    name = models.CharField(max_length=255, unique=True, null=False)
    description = models.TextField(null=True, blank=True)
    start_date = models.DateField(null=True, blank=True)
    end_date = models.DateField(null=True, blank=True)
    tags = models.ManyToManyField(Tag, related_name="trilogies", blank=True)

    def __str__(self):
        return self.name


class Book(models.Model):
    name = models.CharField(max_length=255, unique=True, null=False)
    trilogy = models.ForeignKey(BookTrilogy, on_delete=models.CASCADE, related_name="books")
    publication_date = models.DateField(null=True, blank=True)
    description = models.TextField(null=True, blank=True)
    author = models.CharField(max_length=255, null=True, blank=True)
    created = models.DateTimeField(auto_now_add=True)
    updated = models.DateTimeField(auto_now=True)
    tags = models.ManyToManyField(Tag, related_name="books", blank=True)

    def __str__(self):
        return self.name


class Chapter(models.Model):
    title = models.CharField(max_length=100, null=False)
    notes = models.TextField(null=True, blank=True)
    book = models.ForeignKey(Book, on_delete=models.CASCADE, related_name="chapters")
    chapter_number = models.PositiveIntegerField(null=True, blank=True)
    is_completed = models.BooleanField(default=False)
    created = models.DateTimeField(auto_now_add=True)
    updated = models.DateTimeField(auto_now=True)
    tags = models.ManyToManyField(Tag, related_name="chapters", blank=True)

    def __str__(self):
        return self.title


class SceneContent(models.Model):
    text = models.TextField()

    def __str__(self):
        return self.text[:50]  # Show a preview of the first 50 characters


class SceneDetails(models.Model):
    title = models.CharField(max_length=100, null=False)
    content = models.ForeignKey(SceneContent, on_delete=models.CASCADE, related_name="scene_details")
    created = models.DateTimeField(auto_now_add=True)
    last_edited = models.DateTimeField(auto_now=True)
    is_active = models.BooleanField(default=True)
    created_by = models.ForeignKey('auth.User', on_delete=models.SET_NULL, null=True, blank=True)

    def __str__(self):
        return self.title
