//
// Created by Katrina Tran on 11/11/26.
//

//
// Created by Katrina Tran on 10/26/26.
//

#include <iostream>
#include <string>
#include <vector>
#include "Exercise.h"
#include "Workout.h"
#include "StrengthExercise.h"
#include "CardioExercise.h"
#include <cstdlib>



int main()
{
    // user choices an option until they exit
    int choice;
    std::vector<Exercise> exercises;
    Workout workout;


    do
    {
        std::cout << "WORKOUT TRACKER" << std::endl;
        std::cout << "1. Add Exercise" << std::endl;
        std::cout << "2. View Exercises" << std::endl;
        std::cout << "3. Compare Exercises" << std::endl;
        std::cout << "4. Save Exercises" << std::endl;
        std::cout << "5. Load Exercises" << std::endl;
        std::cout << "6. Add Specialized Exercise" << std::endl;
        std::cout << "7. Analyze Workout (Python)" << std::endl;
        std::cout << "8. Exit" << std::endl;
        std::cout << "Enter your choice: ";

        // if choice is not 1-8, then prompt again
        while (!(std::cin >> choice) || choice < 1 || choice > 8)
        {
            std::cout << "Invalid choice. Please enter a number from 1 to 8: ";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }

        // choice 1 add an exercise
        if (choice == 1)
        {
            std::string name;
            int sets;
            int reps;
            double weight;
            int typeChoice;

            std::cout << "Enter exercise name: ";
            std::cin.ignore();
            std::getline(std::cin, name);

            std::cout << "Enter number of sets: ";
            std::cin >> sets;

            std::cout << "Enter number of reps: ";
            std::cin >> reps;

            std::cout << "Enter weight: ";
            std::cin >> weight;

            // enum to let the user choose exercise type
            std::cout << "Enter exercise type:" << std::endl;
            std::cout << "1. Push" << std::endl;
            std::cout << "2. Pull" << std::endl;
            std::cout << "3. Legs" << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> typeChoice;

            ExerciseType type;

            if (typeChoice == 1)
            {
                type = ExerciseType::PUSH;
            }
            else if (typeChoice == 2)
            {
                type = ExerciseType::PULL;
            }
            else
            {
                type = ExerciseType::LEGS;
            }

            Exercise exercise(name, type, sets, reps, weight);
            exercises.push_back(exercise);
            workout.add_exercise(exercise);

            std::cout << "Exercise added!" << std::endl;
            std::cout << "Volume: " << exercise.calculate_volume() << std::endl;
        }

        // choice 2 view all exercises
        if (choice == 2)
        {
            std::cout << "EXERCISES" << std::endl;

            workout.display_exercises();


            //for (int i = 0; i < exercises.size(); i++)
            //{
            //    std::cout << i + 1 << ". " << exercises[i].get_name() << std::endl;
            //    std::cout << "   Sets: " << exercises[i].get_sets() << std::endl;
            //    std::cout << "   Reps: " << exercises[i].get_reps() << std::endl;
            //    std::cout << "   Weight: " << exercises[i].get_weight() << std::endl;
            //    std::cout << "   Volume: " << exercises[i].calculate_volume() << std::endl;
            //}
        }

        // choice 3 to compare exercises
        if (choice == 3)
        {
            if (exercises.size() < 2)
            {
                std::cout << "You need at least two exercises to compare." << std::endl;
            }
            else
            {
                int first;
                int second;

                std::cout << "Enter the number of the first exercise: ";
                std::cin >> first;

                std::cout << "Enter the number of the second exercise: ";
                std::cin >> second;

                // overloaded operator1
                if (exercises[first - 1] > exercises[second - 1])
                {
                    std::cout << exercises[first - 1].get_name()
                              << " has more volume." << std::endl;
                }
                else if (exercises[second - 1] > exercises[first - 1])
                {
                    std::cout << exercises[second - 1].get_name()
                              << " has more volume." << std::endl;
                }
                else
                {
                    std::cout << "The exercises have the same volume." << std::endl;
                }
            }
        }

        // choice 4 saves the exercises in the Workout object
        if (choice == 4)
        {
            workout.save("workouts.txt");
            std::cout << "Exercises saved to workouts.txt" << std::endl;
        }

        // choice 5 loads exercises from a saved file
        if (choice == 5)
        {
            workout.load("workouts.txt");

            // updates existing vector so comparisons work
            exercises = workout.get_exercises();

            std::cout << "Exercises loaded from workouts.txt" << std::endl;
        }

        // choice 6 lets user choose a specialized exercise type

        if (choice == 6)
        {
            int specializedChoice;
            std::string name;
            int sets;
            int reps;
            double weight;

            std::cout << "1. Strength Exercise" << std::endl;
            std::cout << "2. Cardio Exercise" << std::endl;
            std::cout << "Choose a type: ";
            std::cin >> specializedChoice;
            std::cin.ignore(1000, '\n');

            std::cout << "Enter exercise name: ";
            std::getline(std::cin, name);

            std::cout << "Enter sets: ";
            std::cin >> sets;

            std::cout << "Enter reps: ";
            std::cin >> reps;

            std::cout << "Enter weight: ";
            std::cin >> weight;

            if (specializedChoice == 1)
            {
                std::string muscleGroup;

                std::cout << "Enter muscle group: ";
                std::cin.ignore(1000, '\n');
                std::getline(std::cin, muscleGroup);

                StrengthExercise exercise(name, ExerciseType::PUSH,
                                          sets, reps, weight, muscleGroup);

                std::cout << "Created strength exercise for "
                          << exercise.get_muscle_group() << "." << std::endl;
            }
            else if (specializedChoice == 2)
            {
                int duration;

                std::cout << "Enter duration in minutes: ";
                std::cin >> duration;

                CardioExercise exercise(name, ExerciseType::PULL,
                                        sets, reps, weight, duration);

                std::cout << "Created cardio exercise lasting "
                          << exercise.get_duration_minutes()
                          << " minutes." << std::endl;
            }
            else
            {
                std::cout << "Invalid specialized exercise choice." << std::endl;
            }
        }

        // choice 7 apply the workout_analysis.py to compare exercise stats

        // choice 7 runs the Python workout analysis
        if (choice == 7)
        {
            std::cout << "Synchronizing workout database..." << std::endl;

            int syncResult = system("python3 sync_db.py");

            if (syncResult == 0)
            {
                std::cout << "Running workout analysis..." << std::endl;

                int result = system("python3 workout_analysis.py");

                if (result != 0)
                {
                    std::cout << "There was a problem running the Python script."
                              << std::endl;
                }
            }
            else
            {
                std::cout << "There was a problem synchronizing the database."
                          << std::endl;
            }

            std::cout << "\nReturning to Workout Tracker..." << std::endl;
        }


    } while (choice != 8);

    return 0;
}




