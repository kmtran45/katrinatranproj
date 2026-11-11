//
// Created by Katrina Tran on 10/26/26.
//

#ifndef katrinatranproj_KMTRAN_CARDIOEXERCISE_H
#define katrinatranproj_KMTRAN_CARDIOEXERCISE_H


#include "Exercise.h"
#include <string>

// INHERITANCE EXAMPLE 2:
// CardioExercise IS-A Exercise
class CardioExercise : public Exercise
{
private:
    int duration_minutes;

public:
    // Constructor
    CardioExercise(std::string p_name, ExerciseType p_type,
                   int p_sets, int p_reps, double p_weight,
                   int p_duration_minutes);

    // Returns the cardio duration
    int get_duration_minutes() const;
};

#endif //katrinatranproj_KMTRAN_CARDIOEXERCISE_H
