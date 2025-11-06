import sim
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import time

times, temps, humids, batt = [], [], [], []
start_time = time.time()

fig, axs = plt.subplots(3, 1, figsize=(8, 6))
plt.subplots_adjust(hspace=0.5)

def update(frame):
    current_time = time.time() - start_time
    t, h, b = sim.get_sensor_data()

    times.append(current_time)
    temps.append(t)
    humids.append(h)
    batt.append(b)

    times_trim = times[-15:]
    temps_trim = temps[-15:]
    humids_trim = humids[-15:]
    batt_trim = batt[-15:]

    axs[0].clear()
    axs[0].plot(times_trim, temps_trim, 'r-o')
    axs[0].set_title("Temperature (°C)")
    axs[0].set_ylim(15, 40)

    axs[1].clear()
    axs[1].plot(times_trim, humids_trim, 'b-o')
    axs[1].set_title("Humidity (%)")
    axs[1].set_ylim(20, 90)

    axs[2].clear()
    axs[2].plot(times_trim, batt_trim, 'g-o')
    axs[2].set_title("Battery Level (%)")
    axs[2].set_ylim(0, 110)

    for ax in axs:
        ax.set_xlabel("Time (s)")

    if current_time > 30:
        plt.close()

# Assign animation to a variable to prevent garbage collection
ani = animation.FuncAnimation(fig, update, interval=2000)

plt.show()
