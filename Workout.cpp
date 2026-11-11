//
// Created by Katrina Tran on 11/11/26.
//



#include "Workout.h"
#include <iostream>
#include <fstream>


// Adds an Exercise object to the Workout
void Workout::add_exercise(Exercise exercise)
{
    exercises.push_back(exercise);
}

// Displays all exercises in the Workout
void Workout::display_exercises() const {
    for (int i = 0; i < exercises.size(); i++)
    {
        std::cout << i + 1 << ". "
                  << exercises[i].get_name() << std::endl;

        std::cout << "   Sets: "
                  << exercises[i].get_sets() << std::endl;

        std::cout << "   Reps: "
                  << exercises[i].get_reps() << std::endl;

        std::cout << "   Weight: "
                  << exercises[i].get_weight() << std::endl;

        std::cout << "   Volume: "
                  << exercises[i].calculate_volume() << std::endl;
    }
}

    // the file output that writes exercise information to a text file
    void Workout::save(std::string filename) const
    {
        std::ofstream outFile(filename);

        for (int i = 0; i < exercises.size(); i++)
        {
            outFile << exercises[i].get_name() << ","
                    << static_cast<int>(exercises[i].get_type()) << ","
                    << exercises[i].get_sets() << ","
                    << exercises[i].get_reps() << ","
                    << exercises[i].get_weight() << std::endl;
        }

        outFile.close();
    }

    void Workout::load(std::string filename)
    {
        std::ifstream inFile(filename);

        if (!inFile)
        {
            std::cout << "File not found." << std::endl;
            return;
        }

        std::string name;
        int typeChoice;
        int sets;
        int reps;
        double weight;

        while (std::getline(inFile, name, ','))
        {
            inFile >> typeChoice;
            inFile.ignore(1000, ',');

            inFile >> sets;
            inFile.ignore(1000, ',');

            inFile >> reps;
            inFile.ignore(1000, ',');

            inFile >> weight;
            inFile.ignore(1000, '\n');

            ExerciseType type;

            if (typeChoice == 0)
            {
                type = ExerciseType::PUSH;
            }
            else if (typeChoice == 1)
            {
                type = ExerciseType::PULL;
            }
            else
            {
                type = ExerciseType::LEGS;
            }

            Exercise exercise(name, type, sets, reps, weight);
            exercises.push_back(exercise);
        }

        inFile.close();
    }

    // to return a copy of the exercises stored in the workout
    std::vector<Exercise> Workout::get_exercises() const
    {
        return exercises;
    }

