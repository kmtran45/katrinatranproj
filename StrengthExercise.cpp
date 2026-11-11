//
// Created by Katrina Tran on 11/11/26.
//

#include "StrengthExercise.h"

// Constructor for StrengthExercise
// Passes the exercise information to the Exercise constructor
StrengthExercise::StrengthExercise(std::string p_name, ExerciseType p_type,
                                   int p_sets, int p_reps, double p_weight,
                                   std::string p_muscle_group)
    : Exercise(p_name, p_type, p_sets, p_reps, p_weight)
{
    muscle_group = p_muscle_group;
}

// Returns the muscle group
std::string StrengthExercise::get_muscle_group() const
{
    return muscle_group;
}