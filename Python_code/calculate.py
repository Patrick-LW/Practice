# 实例⼀：南北校区通勤时间计算器

"""
选题理由： 西农南北校区相距约 2.2 公⾥，新⽣经常需要往返两校区上课或办事。教育专线是主要的通勤⽅式。
    该选题难度不高，易上手。
程序功能：让⽤⼾选择出发校区（北校区/南校区）和⽬的地校区。
    程序随机模拟教育专线的等待时间（0-15 分钟）和⾏驶时间（10-25 分钟）。
    输出预计总通勤时间，并给出建议（如“⾼峰期建议提前 10 分钟出发”）。
    统计⽤⼾多次查询的平均通勤时间。
    输入q可随时退出。
运行方式：直接在pycharm运行即可。
AI使用情况：使用deepseek查询random datetime模块处理方法。
    使用deepseek进行功能补充（按‘q’随时退出）。
    使用deepseek查询报错信息与原因，优化逻辑。
    使用deepseek进行外观设计（包括更改字体颜色）
"""


# 载入random,datetime
import random
import datetime

# 封装逻辑（检测出发地、目的地是否合规；输入出发时间并检测是否合规；计算到达时间；输出建议与结果）
def calculate_commute(start, end):
    # 检测出发地、目的地是否合规
    if start == end:
        print("\033[31m出发地和目的地相同！无需乘车！\033[0m") # 这里更改了字体颜色，之后操作相同
        return 'error', None
    if start not in ["北校区", "南校区"]:
        print("\033[31m地点输入有误！出发地只能是北校区/南校区！\033[0m")
        return 'error', None
    if end not in ["北校区", "南校区"]:
        print("\033[31m地点输入有误！目的地只能是北校区/南校区！\033[0m")
        return 'error', None

    # 输入出发时间（循环直到合法）
    while True:
        current_time = input("请输入出发时间（HH:MM）：").strip()
        # 检测是否退出
        if current_time.lower() == 'q':
            return 'q', None
        try:
            start_time = datetime.datetime.strptime(current_time, "%H:%M")
            # 教育专线通行时间预设为 7:30 ~ 19:30
            if start_time.hour >= 20 or start_time.hour <= 7:
                print("\033[33m该时间可能无车辆通行，建议您更换出发时间（教育专线通行时间7：30~19：30）\033[0m")
                continue
            else:
                break
        except ValueError:
            print("\033[31m时间输入格式有误！请按HH:MM格式输入（如10:30）！\033[0m")

    # 模拟等待和行驶时间（随机数使用random模块）
    wait = random.randint(0, 15)
    drive = random.randint(10, 25)

    # 计算到达时间（时间计算使用datetime模块）
    total = wait + drive
    total_time = datetime.timedelta(minutes=total)
    arrive_time = start_time + total_time
    arrive_time = datetime.datetime.strftime(arrive_time, "%H:%M")

    # 生成建议信息
    advice = ""
    if ((start_time.hour == 7 and start_time.minute >= 30)or(start_time.hour == 8 and start_time.minute <= 30))\
            or ((start_time.hour == 14 and start_time.minute >= 30)and(start_time.hour == 15 and start_time.minute <= 30)):
        advice += "当前处于高峰时间段，建议提前十分钟出发。\n"
    if wait > 10:
        advice += "预计等待时间较长。\n"
    if total > 30:
        advice += "预计耗时较长，建议预留充足时间。\n"

    # 输出本次查询结果
    print("本次查询结果为：")
    print(f"预计出发时间为：{start_time.strftime('%H:%M')}")
    print(f"预计等待时间为：{wait}分钟")
    print(f"预计行驶时间为：{drive}分钟")
    print(f"预计总通勤时间为：{total}分钟")
    print(f"预计到达时间为：{arrive_time}")
    if advice:
        print(f"\033[34m建议：{advice}\033[0m")
    else:
        print("\033[34m建议：暂无\033[0m")
    print("-" * 40)
    # 设置返回值，用于检测是否运行有误，以及用于计算平均用时
    return 'ok', total


# =========主程序=========
# 提示信息：
print("=" * 50)
print("        南北校区通勤时间计算器")
print("        (西北农林科技大学 教育专线)")
print("=" * 50)
print("\033[33m说明：模拟等待时间0~15分钟，行驶时间10~25分钟。\033[0m")
print("\033[33m输入'q'退出\n\033[0m")
print("-" * 50)

# 记录（后面用于计算）
count = 0          # 已查询次数
total_sum = 0      # 累计总通勤时间

while True:
    # 输入出发地
    start = input("请输入出发地（北校区/南校区）：").strip()
    # 检测是否退出
    if start.lower() == 'q':
        print("已退出查询")
        break

    # 输入目的地
    end = input("请输入目的地（北校区/南校区）：").strip()
    # 检测是否退出
    if end.lower() == 'q':
        print("已退出查询")
        break

    # 调用计算函数
    status, total = calculate_commute(start, end)

    # 检测程序运行状态
    if status == 'q':
        print("已退出查询")
        break
    elif status == 'error':
        continue
    else:  # status == 'ok'
        #计算
        count += 1
        total_sum += total
        avg_time = total_sum / count
        print(f"已查询{count}次，平均通勤时间：{avg_time:.1f}分钟")
        print("-" * 50)

        # 询问是否继续
        quit = input("按 Enter 继续查询，\033[31m输入'q'退出\033[0m").strip()
        if quit.lower() == 'q':
            break
        else:
            print("-" * 50)

# 最终统计信息
print("\n" + "=" * 50)
if count > 0:
    avg_time = total_sum / count
    print(f"共查询 {count} 次，总平均通勤时间：{avg_time:.1f} 分钟")
else:
    print("没有进行任何查询。")
print("感谢使用！")
print("=" * 50)