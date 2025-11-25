package bg.sofia.uni.fmi.mjt.fittrack;

import bg.sofia.uni.fmi.mjt.fittrack.exception.OptimalPlanImpossibleException;
import bg.sofia.uni.fmi.mjt.fittrack.workout.Workout;
import bg.sofia.uni.fmi.mjt.fittrack.workout.WorkoutType;
import bg.sofia.uni.fmi.mjt.fittrack.workout.comparators.WorkoutByBurnedCaloriesDescThenByDifficultyDescComparator;
import bg.sofia.uni.fmi.mjt.fittrack.workout.comparators.WorkoutByDifficultyComparator;
import bg.sofia.uni.fmi.mjt.fittrack.workout.filter.WorkoutFilter;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class FitPlanner implements FitPlannerAPI {
    private Collection<Workout> availableWorkouts;

    public FitPlanner(Collection<Workout> availableWorkouts) {
        setAvailableWorkouts(availableWorkouts);
    }

    public void setAvailableWorkouts(Collection<Workout> availableWorkouts) {
        if (availableWorkouts == null) {
            throw new IllegalArgumentException("availableWorkouts is null");
        }
        this.availableWorkouts = List.copyOf(availableWorkouts);
    }

    @Override
    public List<Workout> findWorkoutsByFilters(List<WorkoutFilter> filters) {
        if (filters == null) {
            throw new IllegalArgumentException("filters is null");
        }

        List<Workout> result = new ArrayList<>();
        for (Workout workout : availableWorkouts) {
            boolean matchesAll = true;
            for (WorkoutFilter filter : filters) {
                if (!filter.matches(workout)) {
                    matchesAll = false;
                    break;
                }
            }
            if (matchesAll) {
                result.add(workout);
            }
        }
        return result;
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
        int n = workoutList.size();

        int[] maxCalories = new int[totalMinutes + 1];
        boolean[][] selected = new boolean[totalMinutes + 1][n];

        for (int i = 0; i < n; i++) {
            Workout workout = workoutList.get(i);
            int calories = workout.getCaloriesBurned();
            int duration = workout.getDuration();

            for (int j = totalMinutes; j >= duration; j--) {
                if (maxCalories[j] < maxCalories[j - duration] + calories) {
                    maxCalories[j] = maxCalories[j - duration] + calories;
                    if (j - duration >= 0) {
                        System.arraycopy(selected[j - duration], 0, selected[j], 0, n);
                    }
                    selected[j][i] = true;
                }
            }
        }

        if (maxCalories[totalMinutes] == 0) {
            throw new OptimalPlanImpossibleException("No workout combination fits within the given time limit");
        }

        List<Workout> result = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (selected[totalMinutes][i]) {
                result.add(workoutList.get(i));
            }
        }

        result.sort(new WorkoutByBurnedCaloriesDescThenByDifficultyDescComparator());
        return result;
    }

    @Override
    public Map<WorkoutType, List<Workout>> getWorkoutsGroupedByType() {
        Map<WorkoutType, List<Workout>> map = new HashMap<>();

        for (Workout workout : availableWorkouts) {
            WorkoutType type = workout.getType();
            List<Workout> workoutsOfType = map.get(type);
            if (workoutsOfType == null) {
                workoutsOfType = new ArrayList<>();
                map.put(type, workoutsOfType);
            }
            workoutsOfType.add(workout);
        }

        return Collections.unmodifiableMap(map);
    }

    @Override
    public List<Workout> getWorkoutsSortedByCalories() {
        List<Workout> sorted = new ArrayList<>(availableWorkouts);
        sorted.sort(new WorkoutByBurnedCaloriesDescThenByDifficultyDescComparator());
        return Collections.unmodifiableList(sorted);
    }

    @Override
    public List<Workout> getWorkoutsSortedByDifficulty() {
        List<Workout> sorted = new ArrayList<>(availableWorkouts);
        sorted.sort(new WorkoutByDifficultyComparator());
        return Collections.unmodifiableList(sorted);
    }

    @Override
    public Set<Workout> getUnmodifiableWorkoutSet() {
        return Set.copyOf(availableWorkouts);
    }
}