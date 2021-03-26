# 操作索引

## 新建索引

```
PUT /test_index
{
  "mappings": {
    "test_type": {
      "properties": {
        "test_name":{
          "type": "text"
        },
        "test_content":{
          "analyzer": "ik_smart",
          "type": "text"
        }
      }
    }
  }
}
```

## 新增索引字段

```
PUT /test_index/_mapping/test_type
{
  "properties": {
    "sort_factor":{
      "type": "long"
    }
  }
}
```

## 删除索引

```
DELETE /test_index
```

# 操作记录

## 插入数据

```
PUT /test_index/test_type/1
{
  "test_name": "tanglichen",
  "test_content": "hello world"
}
```

## 更新数据

- https://www.elastic.co/guide/en/elasticsearch/reference/current/docs-update.html#docs-update-api-path-params

```
POST test_index/test_type/1/_update
{
  "script" : "ctx._source.test_content='hello lizongliang'"
}
```

## 删除数据

```
DELETE test_index/test_type/1
 
删除全部数据
DELETE /trial_assistant_student_list/doc/_query
    {
        "query": {
        "match_all": {}
    }
}
```

# 数据查询

- https://www.elastic.co/guide/en/elasticsearch/reference/current/query-dsl.html

## match

```
GET test_index/test_type/_search
{
  "query" : { "match" : { "test_content" : "唐立臣" }}
}
```

## bool运算

### 或运算

```
GET test_index/test_type/_search
{
  "query" : { "match" : { "test_content" : "唐立臣 hello" }}
}
```

### 与运算

```
GET test_index/test_type/_search
{
  "query": {
    "bool": {
      "must": [
        { "match": { "test_content": "你好" } },
        { "match": { "test_content": "唐立臣" } }
      ]
    }
  }
}
```

### 查询null字段

```
GET /trial_assistant_student_list/_search
{
  "query": {
    "bool": {
      "must_not": [
        {"exists": {
          "field": "assistant_id"
        }}
      ]
    }
  }
}
```

# 排序与分页

## 修改数据属性支持排序

```
GET test_index/_mapping/test_type/
{
  "properties": {
    "test_name": {
      "type":     "text",
      "fielddata": true
    }
  }
}
```

## 排序与分页

```
# 对应数据为(10~14,从零开始)
GET /test_index/test_type/_search
{
  "size": 5,
  "from": 10,
  "sort": [
    {
      "test_name": {
        "order": "desc"
      }
    }
  ]
}
```

# 数据结构

- https://www.elastic.co/guide/en/elasticsearch/reference/current/mapping-types.html