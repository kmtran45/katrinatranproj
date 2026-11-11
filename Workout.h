//
// Created by Katrina Tran on 11/11/26.
//

#ifndef KATRINATRANPROJ_WORKOUT_H
#define KATRINATRANPROJ_WORKOUT_H


#include <vector>
#include <string>
#include "Exercise.h"

// CLASS 2: Workout
// A Workout contains multiple Exercise objects.
class Workout
{
private:
    // Component relationship: Workout HAS-A collection of Exercise objects
    std::vector<Exercise> exercises;

public:
    // Adds an Exercise to the Workout
    void add_exercise(Exercise exercise);

    // Displays the exercises in the Workout
    void display_exercises() const;

    // the file output to save the workout exercises to a file
    void save(std::string filename) const;

    // file input to load exercises from a text file
    void load(std::string filename);

    // to return the exercises stored in the Workout
    std::vector<Exercise> get_exercises() const;

};

#endif //KATRINATRANPROJ_WORKOUT_H
