//
// Created by Katrina Tran on 11/11/26.
//

#include "CardioExercise.h"

// Constructor for CardioExercise
// Passes the exercise information to the Exercise constructor
CardioExercise::CardioExercise(std::string p_name, ExerciseType p_type,
                               int p_sets, int p_reps, double p_weight,
                               int p_duration_minutes)
    : Exercise(p_name, p_type, p_sets, p_reps, p_weight)
{
    duration_minutes = p_duration_minutes;
}

// Returns the cardio duration
int CardioExercise::get_duration_minutes() const
{
    return duration_minutes;
}