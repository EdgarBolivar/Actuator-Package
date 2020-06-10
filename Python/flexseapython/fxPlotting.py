from flexseapython.pyFlexsea import *
import matplotlib.pyplot as plt
# import matplotlib		# Not used

# Figure: setpoint, desired vs measured
def plotSetpointVsDesired(devId, figCounter, controllerType, signalFrequency, signalAmplitude,
	signalTypeStr, commandFrequency, times, requests, measurements, cycleStopTimes):
	"""
	Plot setpoint, desired vs. measured.

	Args:
	  devId:			Unique Identified for each connected device.
	  fig:				Chart counter.  Incremented with every new chart.
	  controllerType:	Position controller or current controller.
	  signalFrequency:	Frequency of sine wave if using sine wave signal.
	  signalAmplitude:	Amplitude of signal to send to controller.
						Encoder position if position controller,
						current in mA if current controller
	  signalTypeStr:	Sine wave or line.
	  commandFrequency: Desired frequency of issuing commands to controller, actual
						command frequency will be slower due to OS overhead.
	  times:			Time stamps
	  requests:			Values requested
	  measurements:		Actual measured values
	  cycleStopTimes:	Used to draw a vertical line at the end of each cycle
	"""

	plt.figure(figCounter)
	figCounter += 1

	# Specific to the current controller:
	if(controllerType == hssCurrent):	#Controller.current):

		title = "Current control with " + "{:.2f}".format(signalFrequency) + " Hz, " + \
			str(signalAmplitude) + " mA " + signalTypeStr + " and " + \
				"{:.2f}".format(commandFrequency) + " Hz commands" + ' (ID:' + str(devId) + ')'
		plt.ylabel("Motor current (mA)")

	# Specific to the position controller:
	elif(controllerType == hssPosition):	#Controller.position):

		title = "Position control with " + "{:.2f}".format(signalFrequency) + " Hz, " + \
			str(signalAmplitude) + " ticks " + signalTypeStr + " and " + \
				"{:.2f}".format(commandFrequency) + " Hz commands" + ' (ID:' + str(devId) + ')'
		plt.ylabel("Encoder position")
	else:			# Defensive code: Avoid 'Reference before Assignment' warning
		title = ""

	# Common info:
	plt.plot(times, requests, color='b', label='Desired')
	plt.plot(times, measurements, color='r', label='Measured')
	plt.xlabel("Time (s)")
	plt.title(title)
	plt.legend(loc='upper right')

	# Draw a vertical line at the end of each cycle
	for endpoints in cycleStopTimes:
		plt.axvline(x=endpoints, color='xkcd:light grey')

	return figCounter

# Multiple figures: command and stream times in linear and occurrence log
# Supports two types at once
def plotExpStats(devId, figCounter, writeCommandTimes, readCommandTimes):
	figCounter = plotExpStatsOneType(devId, figCounter, writeCommandTimes, "Write")
	figCounter = plotExpStatsOneType(devId, figCounter, readCommandTimes, "Read")
	return fig

# Two figures: command and stream times in linear and occurrence log
def plotExpStatsOneType(devId, figCounter, actionTimes, title):

	# Figure: command time vs time, linear scale
	plt.figure(figCounter)
	figCounter += 1
	actionTimes = [i * 1000 for i in actionTimes]
	# Convert command times into ms
	plt.plot(actionTimes, color='b', label='Times')
	plt.title(title + " Time vs Time" ' (ID:' + str(devId) + ')')
	plt.legend(loc='upper right')
	plt.xlabel("Time (ms)")
	plt.ylabel("Command Time (ms)")

	# Figure: time occurrences, log
	plt.figure(figCounter)
	figCounter += 1
	plt.yscale('log')
	plt.hist(actionTimes, bins=100, label = 'Setpoints')
	plt.yscale('log')
	plt.title(title + " Time Occurrence" + ' (ID:' + str(devId) + ')')
	plt.legend(loc='upper right')
	plt.xlabel("Time (ms)")
	plt.ylabel("Occurrences")

	return figCounter
