"""
.py that analyzes workout data saved by the Workout Tracker
in workouts.txt. calculates workout statistics, including total exercises,
sets, reps, and training volume. It also uses matplotlib to create a bar
graph comparing the training volume of each exercise.C++ manages exercises and saves the workout data, while Python
performs data analysis and visualization.
"""

import sqlite3
import matplotlib.pyplot as plt

# Connect to the workout database.
connection = sqlite3.connect("workout_tracker.db")
cursor = connection.cursor()

# Retrieve exercises from the database using SQL.
cursor.execute("""
               SELECT name, exercise_type, sets, reps, weight
               FROM exercises
               """)

exercises = cursor.fetchall()

# Close the database connection.
connection.close()

# Check whether the database contains exercises.
if len(exercises) == 0:
    print("No exercises found in the database.")
    print("Please add exercises before analyzing your workout.")
else:
    # Calculate workout statistics.
    total_exercises = len(exercises)
    total_sets = 0
    total_reps = 0
    total_volume = 0

    for exercise in exercises:
        name = exercise[0]
        exercise_type = exercise[1]
        sets = exercise[2]
        reps = exercise[3]
        weight = exercise[4]

        total_sets += sets
        total_reps += sets * reps
        total_volume += sets * reps * weight

    # Display workout statistics.
    print("\nWorkout Analysis")
    print("Total Exercises:", total_exercises)
    print("Total Sets:", total_sets)
    print("Total Reps:", total_reps)
    print("Total Training Volume:", total_volume)

    # Prepare exercise names and training volumes for the graph.
    exercise_names = []
    exercise_volumes = []

    for exercise in exercises:
        name = exercise[0]
        sets = exercise[2]
        reps = exercise[3]
        weight = exercise[4]

        exercise_names.append(name)
        exercise_volumes.append(sets * reps * weight)

    # Create a graph of training volume by exercise.
    plt.bar(exercise_names, exercise_volumes)
    plt.title("Training Volume by Exercise")
    plt.xlabel("Exercise")
    plt.ylabel("Training Volume")
    plt.xticks(rotation=45)
    plt.tight_layout()

    # Display the graph.
    plt.show()