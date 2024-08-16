#!/usr/bin/env bash

# Set environment variables for monitors
export MONITOR1=HDMI-0
export MONITOR2=DP-1

# Terminate already running bar instances
# If all your bars have ipc enabled, you can use 
polybar-msg cmd quit
# Otherwise you can use the nuclear option:
killall -q polybar

# Launch bar1 and bar2
echo "---" | tee -a /tmp/polybar1.log /tmp/polybar2.log
MONITOR=$MONITOR1 polybar main 2>&1 | tee -a /tmp/polybar1.log & disown
MONITOR=$MONITOR2 polybar secondary 2>&1 | tee -a /tmp/polybar2.log & disown

echo "Bars launched..."
