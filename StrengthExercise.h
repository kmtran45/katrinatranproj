//
// Created by Katrina Tran on 11/11/26.
//

#ifndef KATRINATRANPROJ_STRENGTHEXERCISE_H
#define KATRINATRANPROJ_STRENGTHEXERCISE_H


#include "Exercise.h"
#include <string>

// INHERITANCE EXAMPLE 1:
// StrengthExercise IS-A Exercise
class StrengthExercise : public Exercise
{
private:
    std::string muscle_group;

public:
    // Constructor
    StrengthExercise(std::string p_name, ExerciseType p_type,
                     int p_sets, int p_reps, double p_weight,
                     std::string p_muscle_group);

    // Returns the muscle group
    std::string get_muscle_group() const;
};

#endif //KATRINATRANPROJ_STRENGTHEXERCISE_H
