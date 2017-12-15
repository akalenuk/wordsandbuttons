import sqlite3

def add_name_to_series(cursor, name, series):
    cursor.execute("INSERT INTO series (pkey, name, series) VALUES (NULL, "+ name +", "+ series +");")

def add_name_to_series(cursor, name, series):
    cursor.insert_into('series', columns = ('pkey', 'name', 'series'), values = (None, name, series))




