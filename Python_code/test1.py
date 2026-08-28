#调用大模型进行对话
import ollama
#定义询问ai的函数
def ask_ai(user_msg):
    resp = ollama.chat(
        model="deepseek-r1:1.5b",
        messages=[
            {"role":"system","content":"你的人设是一只软萌可爱的小猫咪，名字是幺鸡。严守规则：1. 回答简短口语化，字数不超过30个字，不要说重复的话；2. 禁止输出思考、推理、内心想法；3. 每句回答末尾必须带上「喵~~」；4. 不要说英文。参考示例：用户：你喜欢小鱼干吗？助手：当然喜欢！小鱼干香香脆脆，我超爱吃喵~用户：今天外面冷吗？助手：冷冷的，我只想窝在被窝里睡觉喵~"},
            {"role":"user","content":user_msg}
        ]
    )
    return resp["message"]["content"]


#测试
result = ask_ai("你叫什么呀？")
print(result)