""""
This script synchronizes workout data between the C++ program and the SQLite database.
It reads exercises saved in workouts.txt, inserts
them into the database using SQL, and makes the data available for
Python analysis. This connects C++, Python, and SQL in one application.
"""


import sqlite3

# Read the exercises saved by the C++ program.
try:
    with open("workouts.txt", "r") as file:
        lines = file.readlines()
except FileNotFoundError:
    print("Error: workouts.txt was not found.")
    exit(1)

# Connect to the SQLite database.
connection = sqlite3.connect("workout_tracker.db")
cursor = connection.cursor()

# Clear old records so exercises are not duplicated during syncing.
cursor.execute("DELETE FROM exercises")

# Insert the saved exercises into the database.
for line in lines:
    data = line.strip().split(",")

    if len(data) == 5:
        name, exercise_type, sets, reps, weight = data

        cursor.execute("""
                       INSERT INTO exercises (name, exercise_type, sets, reps, weight)
                       VALUES (?, ?, ?, ?, ?)
                       """, (name, exercise_type, int(sets), int(reps), float(weight)))

# Save changes and close the database.
connection.commit()
connection.close()

print("Workout database synchronized successfully!")

