# Workout Tracker

**A Multi-Language Workout Management and Data Analysis Application**

## Project Overview

Workout Tracker is a multi-language application designed to manage exercise records, organize workout data, and provide analytical insights into exercise performance. The application combines **C++, Python, and SQL** to demonstrate object-oriented programming, data persistence, database management, and data visualization within a single software project.

Users can add, view, and compare exercises, save and retrieve workout records, and analyze exercise data through statistical summaries and graphical visualizations.

## Technologies Used

- **C++** – Core application development and workout management
- **Python** – Data analysis and visualization
- **SQL** – Relational database management and data storage
- **Matplotlib** – Graphical data visualization
- **CMake** – Build configuration and project management
- **CLion** – Development environment

## Technical Implementation

### C++ – Application Development

C++ serves as the primary application language and manages the core functionality of the Workout Tracker.

Key implementations include:
- Object-oriented design using multiple classes.
- Inheritance to support specialized exercise types.
- Enumerations for exercise classification.
- Vectors for dynamic exercise storage and management.
- Operator overloading for custom object comparisons.
- File input/output for persistent workout records.
- Interactive menu system for user operations.
- Integration with external Python scripts.

### Python – Data Analysis and Visualization

Python extends the application's functionality by processing workout records and generating analytical insights.

Key implementations include:
- Reading and processing workout data exported from the C++ application.
- Calculating workout statistics, including exercise counts, sets, repetitions, and total training volume.
- Using Matplotlib to generate graphical representations of workout data.
- Presenting analytical results to help users evaluate exercise performance.

### SQL – Database Management

SQL provides structured storage and retrieval of workout records.

Key implementations include:
- Database and table creation.
- Inserting exercise records into the database.
- Retrieving stored exercise information.
- Synchronizing database records with workout data.
- Managing existing records during database updates.

## System Integration

The application demonstrates interoperability between three programming languages through a shared workout data workflow.

1. **C++** manages user interactions, exercise records, and workout operations.
2. Workout information is persisted in a structured text file (`workouts.txt`).
3. **Python** processes the saved records to calculate statistics and generate visualizations.
4. **SQL** provides a relational database for storing, retrieving, and synchronizing exercise information.

This architecture demonstrates how multiple technologies can work together to create a unified application, with each language handling a distinct part of the system.

## Project Structure

| Component | Responsibility |
|---|---|
| C++ source files | Application logic, exercise classes, and workout management |
| `workouts.txt` | Persistent workout data |
| `workout_analysis.py` | Data processing and visualization |
| `setup_db.py` | Database initialization |
| `sync_database.py` | Database synchronization |

## Future Development

Potential improvements and extensions include:

- Expanding database integration and automating data synchronization.
- Improving input validation and error handling.
- Enhancing analytical capabilities with additional workout statistics.
- Introducing historical workout comparisons and progress tracking.
- Improving integration between specialized strength and cardio exercise types.
- Developing additional visualization options for exercise performance.

## Installation and Requirements

The following software and libraries are required to build and run the application:

- CLion or another compatible C++ development environment
- C++ compiler
- CMake
- Python 3
- Matplotlib
- SQL-compatible database environment

## Author

**Katrina Tran**

Mathematics and Statistics | Computer Science Minor

University of Vermont