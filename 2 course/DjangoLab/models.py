# This is an auto-generated Django model module.
# You'll have to do the following manually to clean this up:
#   * Rearrange models' order
#   * Make sure each model has one field with primary_key=True
#   * Make sure each ForeignKey and OneToOneField has `on_delete` set to the desired behavior
#   * Remove `managed = False` lines if you wish to allow Django to create, modify, and delete the table
# Feel free to rename the models, but don't rename db_table values or field names.
from django.db import models


class Actorrole(models.Model):
    id_act_role = models.AutoField(primary_key=True)
    seanceid = models.ForeignKey('Seance', models.DO_NOTHING, db_column='seanceID')  # Field name made lowercase.
    roleid = models.ForeignKey('Role', models.DO_NOTHING, db_column='roleiD')  # Field name made lowercase.
    staffid = models.ForeignKey('Staff', models.DO_NOTHING, db_column='staffID')  # Field name made lowercase.

    class Meta:
        managed = False
        db_table = 'actorrole'


class AuthGroup(models.Model):
    name = models.CharField(unique=True, max_length=150)

    class Meta:
        managed = False
        db_table = 'auth_group'


class AuthGroupPermissions(models.Model):
    group = models.ForeignKey(AuthGroup, models.DO_NOTHING)
    permission = models.ForeignKey('AuthPermission', models.DO_NOTHING)

    class Meta:
        managed = False
        db_table = 'auth_group_permissions'
        unique_together = (('group', 'permission'),)


class AuthPermission(models.Model):
    name = models.CharField(max_length=255)
    content_type = models.ForeignKey('DjangoContentType', models.DO_NOTHING)
    codename = models.CharField(max_length=100)

    class Meta:
        managed = False
        db_table = 'auth_permission'
        unique_together = (('content_type', 'codename'),)


class AuthUser(models.Model):
    password = models.CharField(max_length=128)
    last_login = models.DateTimeField(blank=True, null=True)
    is_superuser = models.IntegerField()
    username = models.CharField(unique=True, max_length=150)
    first_name = models.CharField(max_length=30)
    last_name = models.CharField(max_length=150)
    email = models.CharField(max_length=254)
    is_staff = models.IntegerField()
    is_active = models.IntegerField()
    date_joined = models.DateTimeField()

    class Meta:
        managed = False
        db_table = 'auth_user'


class AuthUserGroups(models.Model):
    user = models.ForeignKey(AuthUser, models.DO_NOTHING)
    group = models.ForeignKey(AuthGroup, models.DO_NOTHING)

    class Meta:
        managed = False
        db_table = 'auth_user_groups'
        unique_together = (('user', 'group'),)


class AuthUserUserPermissions(models.Model):
    user = models.ForeignKey(AuthUser, models.DO_NOTHING)
    permission = models.ForeignKey(AuthPermission, models.DO_NOTHING)

    class Meta:
        managed = False
        db_table = 'auth_user_user_permissions'
        unique_together = (('user', 'permission'),)


class Customer(models.Model):
    id_customer = models.AutoField(primary_key=True)
    customer_name = models.CharField(max_length=100)
    customer_email = models.CharField(max_length=100, blank=True, null=True)
    customer_mobile = models.CharField(max_length=13)

    class Meta:
        managed = False
        db_table = 'customer'


class DjangoAdminLog(models.Model):
    action_time = models.DateTimeField()
    object_id = models.TextField(blank=True, null=True)
    object_repr = models.CharField(max_length=200)
    action_flag = models.PositiveSmallIntegerField()
    change_message = models.TextField()
    content_type = models.ForeignKey('DjangoContentType', models.DO_NOTHING, blank=True, null=True)
    user = models.ForeignKey(AuthUser, models.DO_NOTHING)

    class Meta:
        managed = False
        db_table = 'django_admin_log'


class DjangoContentType(models.Model):
    app_label = models.CharField(max_length=100)
    model = models.CharField(max_length=100)

    class Meta:
        managed = False
        db_table = 'django_content_type'
        unique_together = (('app_label', 'model'),)


class DjangoMigrations(models.Model):
    app = models.CharField(max_length=255)
    name = models.CharField(max_length=255)
    applied = models.DateTimeField()

    class Meta:
        managed = False
        db_table = 'django_migrations'


class DjangoSession(models.Model):
    session_key = models.CharField(primary_key=True, max_length=40)
    session_data = models.TextField()
    expire_date = models.DateTimeField()

    class Meta:
        managed = False
        db_table = 'django_session'


class Hall(models.Model):
    id_hall = models.AutoField(primary_key=True)
    theaterid = models.ForeignKey('Theater', models.DO_NOTHING, db_column='theaterID')  # Field name made lowercase.
    hall_name = models.CharField(max_length=100)
    capacity = models.IntegerField()

    class Meta:
        managed = False
        db_table = 'hall'


class Repertoire(models.Model):
    id_repertoire = models.AutoField(primary_key=True)
    performance_name = models.CharField(max_length=100)
    length = models.TimeField()
    description = models.TextField()
    director = models.CharField(max_length=50, blank=True, null=True)
    artist = models.CharField(max_length=50, blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'repertoire'


class Role(models.Model):
    id_role = models.AutoField(primary_key=True)
    role_name = models.CharField(max_length=255)
    role_description = models.TextField()
    repertoireid = models.ForeignKey(Repertoire, models.DO_NOTHING, db_column='repertoireID')  # Field name made lowercase.

    class Meta:
        managed = False
        db_table = 'role'


class Seance(models.Model):
    id_seance = models.AutoField(primary_key=True)
    date = models.DateField()
    time = models.TimeField()
    hallid = models.ForeignKey(Hall, models.DO_NOTHING, db_column='hallID')  # Field name made lowercase.
    repertoireid = models.ForeignKey(Repertoire, models.DO_NOTHING, db_column='repertoireID')  # Field name made lowercase.
    price = models.IntegerField()

    class Meta:
        managed = False
        db_table = 'seance'


class Staff(models.Model):
    id_staff = models.AutoField(primary_key=True)
    position = models.CharField(max_length=50)
    staff_name = models.CharField(max_length=100)
    salary = models.IntegerField()
    birthday = models.DateField()
    email = models.CharField(max_length=100)
    phone = models.CharField(max_length=13)
    theaterid = models.ForeignKey('Theater', models.DO_NOTHING, db_column='theaterID')  # Field name made lowercase.

    class Meta:
        managed = False
        db_table = 'staff'


class Theater(models.Model):
    id_theater = models.AutoField(primary_key=True)
    theater_name = models.CharField(max_length=100)
    address = models.CharField(max_length=100)
    city = models.CharField(max_length=20)

    class Meta:
        managed = False
        db_table = 'theater'


class Ticket(models.Model):
    id_ticket = models.AutoField(primary_key=True)
    seanceid = models.ForeignKey(Seance, models.DO_NOTHING, db_column='seanceID')  # Field name made lowercase.
    customerid = models.ForeignKey(Customer, models.DO_NOTHING, db_column='customeriD', blank=True, null=True)  # Field name made lowercase.
    place = models.IntegerField(unique=True)
    isreserved = models.CharField(db_column='isReserved', max_length=1)  # Field name made lowercase.

    class Meta:
        managed = False
        db_table = 'ticket'
