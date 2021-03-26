public class Main {
    public List<TrialClassUserAssistant> batchGetByUserOrderPairs(List<UserOrderPair> userOrderPairList) {
        if (CollectionUtils.isEmpty(userOrderPairList)) {
            return Collections.emptyList();
        }

        List<String[]> valuesMap = new ArrayList<>();
        userOrderPairList.forEach(userOrderPair -> {
            String[] userOrderPairArray = {String.valueOf(userOrderPair.getUserId()), String.valueOf(userOrderPair.getOrderId())};
            valuesMap.add(userOrderPairArray);
        });

        final String sql = "SELECT * FROM trial_class_user_assistant WHERE (userId, orderId) IN (:valuesMap)";

        MapSqlParameterSource source = new MapSqlParameterSource()
                .addValue("valuesMap", valuesMap);

        return db.query(sql, source, ROW_MAPPER);
    }
}

