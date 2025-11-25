package bg.sofia.uni.fmi.mjt.fittrack.workout.filter;

import bg.sofia.uni.fmi.mjt.fittrack.workout.Workout;

public class NameWorkoutFilter implements WorkoutFilter {

    private String keyWord;
    private boolean caseSensitive;

    public NameWorkoutFilter(String keyword, boolean caseSensitive){
        setKeyWord(keyword);
        setCaseSensitive(caseSensitive);
    }

    public boolean isCaseSensitive() {
        return caseSensitive;
    }

    public void setCaseSensitive(boolean caseSensitive) {
        this.caseSensitive = caseSensitive;
    }

    public String getKeyWord() {
        return keyWord;
    }

    public void setKeyWord(String keyWord) {
        if(keyWord == null|| keyWord.isEmpty()){
            throw new IllegalArgumentException("keyWord can't be null");
        }
        this.keyWord = keyWord;
    }

    @Override
    public boolean matches(Workout workout) {
        if (workout == null) {
            return false;
        }

        if (caseSensitive) {
            return workout.getName().contains(keyWord);
        } else {
            return workout.getName().toLowerCase().contains(keyWord.toLowerCase());
        }
    }
}
