package bg.sofia.uni.fmi.mjt.show.elimination;

import bg.sofia.uni.fmi.mjt.show.ergenka.Ergenka;

public class LowestRatingEliminationRule implements EliminationRule {


    @Override
    public Ergenka[] eliminateErgenkas(Ergenka[] ergenkas) {
        if (ergenkas == null || ergenkas.length == 0) {
            return ergenkas;
        }
        int minRating = ergenkas[0].getRating();
        for (Ergenka ergenka : ergenkas) {
            if (ergenka.getRating() < minRating)
                minRating = ergenka.getRating();
        }

        int toRemove = 0;
        for (Ergenka ergenka : ergenkas) {
            if (ergenka.getRating() == minRating)
                toRemove++;
        }

        Ergenka[] newErgenkas = new Ergenka[ergenkas.length - toRemove];
        int newErgenkaIndex = 0;
        for (int i = 0; i < ergenkas.length; i++) {
            if(ergenkas[i].getRating() != minRating){
                newErgenkas[newErgenkaIndex++] = ergenkas[i];
            }
        }
        return newErgenkas;
    }
}
