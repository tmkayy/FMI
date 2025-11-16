package bg.sofia.uni.fmi.mjt.show.elimination;

import bg.sofia.uni.fmi.mjt.show.ergenka.Ergenka;

public class LowestRatingEliminationRule implements EliminationRule {

    @Override
    public Ergenka[] eliminateErgenkas(Ergenka[] ergenkas) {
        if (ergenkas == null || ergenkas.length == 0) {
            return new Ergenka[0];
        }

        int minRating = Integer.MAX_VALUE;
        for (Ergenka ergenka : ergenkas) {
            if (ergenka != null && ergenka.getRating() < minRating) {
                minRating = ergenka.getRating();
            }
        }

        if (minRating == Integer.MAX_VALUE) {
            return new Ergenka[0];
        }

        int toRemove = 0;
        for (Ergenka ergenka : ergenkas) {
            if (ergenka != null && ergenka.getRating() == minRating) {
                toRemove++;
            }
        }

        Ergenka[] newErgenkas = new Ergenka[ergenkas.length - toRemove];
        int newErgenkaIndex = 0;
        for (int i = 0; i < ergenkas.length; i++) {
            // Add null check
            if (ergenkas[i] != null && ergenkas[i].getRating() != minRating) {
                newErgenkas[newErgenkaIndex++] = ergenkas[i];
            }
        }
        return newErgenkas;
    }
}