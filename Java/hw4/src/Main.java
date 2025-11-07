import bg.sofia.uni.fmi.mjt.fittrack.FitPlanner;
import bg.sofia.uni.fmi.mjt.fittrack.exception.OptimalPlanImpossibleException;
import bg.sofia.uni.fmi.mjt.fittrack.workout.CardioWorkout;
import bg.sofia.uni.fmi.mjt.fittrack.workout.StrengthWorkout;
import bg.sofia.uni.fmi.mjt.fittrack.workout.Workout;
import bg.sofia.uni.fmi.mjt.fittrack.workout.YogaSession;

void main() {
    List<Workout> workouts = Arrays.asList(
            new CardioWorkout("HIIT", 30, 400, 4),
            new StrengthWorkout("Upper Body", 45, 350, 3),
            new YogaSession("Morning Flow", 20, 150, 2),
            new CardioWorkout("Cycling", 60, 600, 5),
            new StrengthWorkout("Leg Day", 30, 250, 2),
            new YogaSession("Evening Relax", 15, 100, 1)
    );

    FitPlanner planner = new FitPlanner(workouts);
    try {
        List<Workout> plan = planner.generateOptimalWeeklyPlan(120);
        for (Workout w : plan) {
            System.out.println(w);
        }
    } catch (OptimalPlanImpossibleException e){
        e.printStackTrace();
    }
}
