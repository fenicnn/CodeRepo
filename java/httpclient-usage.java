/**
 * @(#)EnvironmentType.java, 1月 08, 2021.
 * <p>
 * Copyright 2021 fenbi.com. All rights reserved.
 * FENBI.COM PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */
package com.fenbi.conan.zis.commons.notification;

import com.fasterxml.jackson.annotation.JsonProperty;
import com.fenbi.common.util.JsonUtils;
import com.google.common.base.Charsets;
import lombok.Getter;
import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.apache.http.HttpEntity;
import org.apache.http.client.config.RequestConfig;
import org.apache.http.client.methods.CloseableHttpResponse;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.entity.StringEntity;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.HttpClients;
import org.apache.http.util.EntityUtils;
import org.springframework.http.MediaType;
import org.springframework.util.CollectionUtils;

import java.io.IOException;
import java.util.Collections;
import java.util.List;
import java.util.concurrent.TimeUnit;

/**
 * @author chennannan
 */
@Slf4j
public class WxWorkNotificationUtil {

    // 传输超时时间
    private static final int SOCKET_TIMEOUT = (int)TimeUnit.SECONDS.toMillis(10);
    // 连接超时时间
    private static final int CONNECT_TIMEOUT = (int)TimeUnit.SECONDS.toMillis(2);
    // 从连接池获取连接超时时间
    private static final int CONNECTION_REQUEST_TIMEOUT = (int)TimeUnit.SECONDS.toMillis(2);
    // 企业微信api
    private static final String WECHAT_API = "https://oa.zhenguanyu.com/weixin/";

    private static final RequestConfig REQUEST_CONFIG = RequestConfig.custom()
            .setConnectTimeout(CONNECT_TIMEOUT)
            .setConnectionRequestTimeout(CONNECTION_REQUEST_TIMEOUT)
            .setSocketTimeout(SOCKET_TIMEOUT)
            .build();

    private static final CloseableHttpClient CLOSEABLE_HTTP_CLIENT = HttpClients.custom()
            .setDefaultRequestConfig(REQUEST_CONFIG)
            .setMaxConnTotal(256)
            .setMaxConnPerRoute(256)
            .build();

    /**
     * @param ldaps   触达对象
     * @param message 触达消息
     */
    public static void sendToLdaps(List<String> ldaps, String message) {
        sendToLdaps(ldaps, message, null);
    }

    /**
     * @param ldaps           触达对象
     * @param message         触达消息
     * @param environmentType 发送触达的服务环境
     */
    public static void sendToLdaps(List<String> ldaps, String message, EnvironmentType environmentType) {
        try {
            if (environmentType != null) {
                message = environmentType.toShowName() + message;
            }
            send(new MessageBody(ldaps, Collections.emptyList(), message));
        } catch (Exception e) {
            log.error("send ldap msg failed, ldaps=[{}], message=[{}]", ldaps, message, e);
        }
    }

    private static void send(MessageBody messageBody) {
        if (CollectionUtils.isEmpty(messageBody.getReceivers()) && CollectionUtils.isEmpty(messageBody.getReceiverGroups())) {
            throw new IllegalArgumentException("empty receivers");
        }

        StringEntity entity = new StringEntity(JsonUtils.writeValue(messageBody), Charsets.UTF_8);
        entity.setContentType(MediaType.APPLICATION_JSON_UTF8_VALUE);
        HttpPost post = new HttpPost(WECHAT_API);
        post.setEntity(entity);

        // try-with-resources, 会自动调用response.close();
        try(CloseableHttpResponse response = CLOSEABLE_HTTP_CLIENT.execute(post)){
            EntityUtils.consume(response.getEntity());
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    @Getter
    @RequiredArgsConstructor
    private static class MessageBody {

        @JsonProperty("touser")
        private final List<String> receivers;
        @JsonProperty("toparty")
        private final List<String> receiverGroups;
        private final String content;
    }
}
