import sqlite3

# Connect to the workout database.
# If it does not exist, SQLite will create it.
connection = sqlite3.connect("workout_tracker.db")

# Create a cursor to execute SQL commands.
cursor = connection.cursor()

# Create a table to store exercises.
cursor.execute("""
               CREATE TABLE IF NOT EXISTS exercises (
                                                        id INTEGER PRIMARY KEY AUTOINCREMENT,
                                                        name TEXT NOT NULL,
                                                        exercise_type TEXT NOT NULL,
                                                        sets INTEGER NOT NULL,
                                                        reps INTEGER NOT NULL,
                                                        weight REAL NOT NULL
               )
               """)

# Save the database changes.
connection.commit()

# Close the database connection.
connection.close()

print("Workout database created successfully")
