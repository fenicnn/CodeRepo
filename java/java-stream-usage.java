public Map<Long, TrialClassUserAssistant> batchGetLatestUserAssistantByUserIds(List<Long> userIds){
        return trialClassUserAssistantStorage.getUserAssistantsByUserIds(userIds)
        .stream()
        .collect(Collectors.toMap(
        TrialClassUserAssistant::getUserId,
        Function.identity(),
        BinaryOperator.maxBy(Comparator.comparingLong(TrialClassUserAssistant::getCreateTime))));
        }