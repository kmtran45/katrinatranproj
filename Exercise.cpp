//
// Created by Katrina Tran on 10/26/26.
//


#include "Exercise.h"

// the default exercise constructor
Exercise::Exercise()
{
    name = "";
    type = ExerciseType::PUSH;
    sets = 0;
    reps = 0;
    weight = 0;
}

// constructor for exercise with user provided info
Exercise::Exercise(std::string p_name, ExerciseType p_type, int p_sets, int p_reps, double p_weight)
{
    name = p_name;
    type = p_type;
    sets = p_sets;
    reps = p_reps;
    weight = p_weight;
}

// getters

std::string Exercise::get_name() const
{
    return name;
}

ExerciseType Exercise::get_type() const
{
    return type;
}

int Exercise::get_sets() const
{
    return sets;
}

int Exercise::get_reps() const
{
    return reps;
}

double Exercise::get_weight() const
{
    return weight;
}

// setters
void Exercise::set_name(std::string p_name)
{
    name = p_name;
}

void Exercise::set_type(ExerciseType p_type)
{
    type = p_type;
}

void Exercise::set_sets(int p_sets)
{
    sets = p_sets;
}

void Exercise::set_reps(int p_reps)
{
    reps = p_reps;
}

void Exercise::set_weight(double p_weight)
{
    weight = p_weight;
}

// to calculate volume
double Exercise::calculate_volume() const
{
    return sets * reps * weight;
}

// overloaded operator to compare exercises
// exercise with the greater volume is the greater exercise
bool Exercise::operator>(const Exercise& other) const
{
    return calculate_volume() > other.calculate_volume();
}
