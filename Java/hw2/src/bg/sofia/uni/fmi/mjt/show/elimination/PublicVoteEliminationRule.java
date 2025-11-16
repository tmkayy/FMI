package bg.sofia.uni.fmi.mjt.show.elimination;

import bg.sofia.uni.fmi.mjt.show.ergenka.Ergenka;

public class PublicVoteEliminationRule implements EliminationRule {

    private final String[] votes;

    public PublicVoteEliminationRule(String[] votes) {
        this.votes = votes;
    }

    public String[] getVotes() {
        return votes;
    }

    @Override
    public Ergenka[] eliminateErgenkas(Ergenka[] ergenkas) {
        if (ergenkas == null || ergenkas.length == 0 || votes == null || votes.length == 0) {
            return ergenkas;
        }

        int[] counts = new int[ergenkas.length];
        for (String vote : votes) {
            for (int i = 0; i < ergenkas.length; i++) {
                if (ergenkas[i].getName().equals(vote)) {
                    counts[i]++;
                    break;
                }
            }
        }

        int majorityIndex = -1;
        for (int i = 0; i < counts.length; i++) {
            if (counts[i] > votes.length / 2) {
                majorityIndex = i;
                break;
            }
        }

        if (majorityIndex == -1) {
            return ergenkas;
        }

        Ergenka[] newErgenkas = new Ergenka[ergenkas.length - 1];
        int newIndex = 0;
        for (int i = 0; i < ergenkas.length; i++) {
            if (i != majorityIndex) {
                newErgenkas[newIndex++] = ergenkas[i];
            }
        }
        return newErgenkas;
    }
}