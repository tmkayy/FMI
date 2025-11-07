package bg.sofia.uni.fmi.mjt.fittrack;

import bg.sofia.uni.fmi.mjt.fittrack.exception.OptimalPlanImpossibleException;
import bg.sofia.uni.fmi.mjt.fittrack.workout.Workout;
import bg.sofia.uni.fmi.mjt.fittrack.workout.WorkoutType;
import bg.sofia.uni.fmi.mjt.fittrack.workout.filter.WorkoutFilter;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class FitPlanner implements FitPlannerAPI{
    private Collection<Workout> availableWorkouts;

    public FitPlanner(Collection<Workout> availableWorkouts){
        setAvailableWorkouts(availableWorkouts);
    }

    public Collection<Workout> getAvailableWorkouts() {
        return availableWorkouts;
    }

    public void setAvailableWorkouts(Collection<Workout> availableWorkouts) {
        if(availableWorkouts==null){
            throw new IllegalArgumentException("availableWorkouts is null");
        }
        this.availableWorkouts = availableWorkouts;
    }

    @Override
    public List<Workout> findWorkoutsByFilters(List<WorkoutFilter> filters) {
        if(filters==null){
            throw new IllegalArgumentException("filters is null");
        }
        Set<Workout> workouts = new HashSet<>();
        for (WorkoutFilter filter : filters) {
            for(Workout workout : getAvailableWorkouts()) {
                if(filter.matches(workout)){
                    workouts.add(workout);
                }
            }
        }
        return new ArrayList<>(workouts);
    }

    @Override
    public List<Workout> generateOptimalWeeklyPlan(int totalMinutes) throws OptimalPlanImpossibleException {
        if (totalMinutes < 0) {
            throw new IllegalArgumentException("totalMinutes is negative");
        }

        if (totalMinutes == 0) {
            return new ArrayList<>();
        }

        List<Workout> workoutList = new ArrayList<>(availableWorkouts);

        int[] dp = new int[totalMinutes + 1];
        Workout[] lastWorkout = new Workout[totalMinutes + 1];

        for (Workout workout : workoutList) {
            int calories = workout.getCaloriesBurned();
            int duration = workout.getDuration();

            for (int j = totalMinutes; j >= duration; j--) {
                if (dp[j] < dp[j - duration] + calories) {
                    dp[j] = dp[j - duration] + calories;
                    lastWorkout[j] = workout;
                }
            }
        }

        if (dp[totalMinutes] == 0) {
            throw new OptimalPlanImpossibleException("No workout combination fits within the given time limit");
        }

        List<Workout> result = new ArrayList<>();
        int remainingTime = totalMinutes;
        while (remainingTime > 0 && lastWorkout[remainingTime] != null) {
            Workout workout = lastWorkout[remainingTime];
            result.add(workout);
            remainingTime -= workout.getDuration();
        }

        return result;
    }

    @Override
    public Map<WorkoutType, List<Workout>> getWorkoutsGroupedByType() {
        Map<WorkoutType, List<Workout>> map = new HashMap<>();
        for(WorkoutType workoutType : WorkoutType.values()){
            map.put(workoutType, new ArrayList<>());
        }
        for(Workout workout : availableWorkouts){
            map.get(workout.getType()).add(workout);
        }

        return map;
    }

    @Override
    public List<Workout> getWorkoutsSortedByCalories() {
        ArrayList<Workout> workouts = new ArrayList<>(availableWorkouts);
        workouts.sort(new Comparator<>() {
            @Override
            public int compare(Workout w1, Workout w2) {
                return Integer.compare(w2.getCaloriesBurned(), w1.getCaloriesBurned());
            }
        });

        return  List.copyOf(workouts);
    }

    @Override
    public List<Workout> getWorkoutsSortedByDifficulty() {
        ArrayList<Workout> workouts = new ArrayList<>(availableWorkouts);
        workouts.sort(new Comparator<>() {
            @Override
            public int compare(Workout w1, Workout w2) {
                return Integer.compare(w1.getDifficulty(), w2.getDifficulty());
            }
        });

        return  List.copyOf(workouts);
    }

    @Override
    public Set<Workout> getUnmodifiableWorkoutSet() {
        return Set.copyOf(new HashSet<>(availableWorkouts));
    }
}
