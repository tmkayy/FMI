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

        int countAboveMin = 0;
        for (Ergenka ergenka : ergenkas) {
            if (ergenka != null && ergenka.getRating() > minRating) {
                countAboveMin++;
            }
        }

        if (countAboveMin > 0) {
            Ergenka[] result = new Ergenka[countAboveMin];
            int index = 0;
            for (Ergenka ergenka : ergenkas) {
                if (ergenka != null && ergenka.getRating() > minRating) {
                    result[index++] = ergenka;
                }
            }
            return result;
        }

        return new Ergenka[0];
    }
}