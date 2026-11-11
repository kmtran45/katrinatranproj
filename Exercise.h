//
// Created by Katrina Tran on 11/11/26.
//

#ifndef KATRINATRANPROJ_EXERCISE_H
#define KATRINATRANPROJ_EXERCISE_H


#include <string>

// enum creates a type with a set of possible exercise types
enum class ExerciseType
{
    PUSH,
    PULL,
    LEGS
};
// this class represents an exercise and stores the info about it
class Exercise
{
private:
    // the exercise fields
    std::string name;
    ExerciseType type;
    int sets;
    int reps;
    double weight;

public:
    // constructors
    Exercise();
    Exercise(std::string p_name, ExerciseType p_type, int p_sets, int p_reps, double p_weight);

    // getters
    std::string get_name() const;
    ExerciseType get_type() const;
    int get_sets() const;
    int get_reps() const;
    double get_weight() const;

    // setters
    void set_name(std::string p_name);
    void set_type(ExerciseType p_type);
    void set_sets(int p_sets);
    void set_reps(int p_reps);
    void set_weight(double p_weight);

    // to find the volume of an exercise
    double calculate_volume() const;

    // the overloaded operator to compare 2 exercises
    bool operator>(const Exercise& other) const;
};



#endif //KATRINATRANPROJ_EXERCISE_H
