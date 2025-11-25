package bg.sofia.uni.fmi.mjt.show.elimination;

import bg.sofia.uni.fmi.mjt.show.ergenka.Ergenka;

public class LowAttributeSumEliminationRule implements EliminationRule {

    private final int threshold;

    public LowAttributeSumEliminationRule(int threshold) {
        this.threshold = threshold;
    }

    int getThreshold() {
        return threshold;
    }

    @Override
    public Ergenka[] eliminateErgenkas(Ergenka[] ergenkas) {
        if (ergenkas == null || ergenkas.length == 0) {
            return new Ergenka[0];
        }

        int toRemove = 0;
        for (Ergenka ergenka : ergenkas) {
            if (ergenka != null && ergenka.getHumorLevel() + ergenka.getRomanceLevel() < threshold) {
                toRemove++;
            }
        }

        Ergenka[] newErgenkas = new Ergenka[ergenkas.length - toRemove];
        int newErgenkaIndex = 0;
        for (int i = 0; i < ergenkas.length; i++) {
            // Add null check
            if (ergenkas[i] != null && ergenkas[i].getHumorLevel() + ergenkas[i].getRomanceLevel() >= threshold) {
                newErgenkas[newErgenkaIndex++] = ergenkas[i];
            }
        }
        return newErgenkas;
    }
}