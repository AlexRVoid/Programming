import React, { useState } from 'react';
import { Calendar, momentLocalizer } from 'react-big-calendar';
import moment from 'moment';
import 'react-big-calendar/lib/css/react-big-calendar.css';
import DatePicker from 'react-datepicker';
import 'react-datepicker/dist/react-datepicker.css';
import './styles/calendar.css';

const localizer = momentLocalizer(moment);

const Post = () => {
    const [newEvent, setNewEvent] = useState({ title: '', start: null, end: null });
    const [allEvents, setAllEvents] = useState([]);

    const handleAddEvent = () => {
        if (!newEvent.title || !newEvent.start || !newEvent.end) {
            alert('Please enter all fields');
            return;
        }

        const updatedEvents = [...allEvents, newEvent];
        setAllEvents(updatedEvents);
        setNewEvent({ title: '', start: null, end: null });
    };

    const handleSelectSlot = (slotInfo) => {
        const start = slotInfo.start;
        const end = slotInfo.end;

        setNewEvent({ ...newEvent, start, end });
    };

    return (
        <div className="App">
            <h1>Calendar</h1>
            <h2>Add New Event</h2>
            <div>
                <form className="Inputbox">
                    <input
                        value={newEvent.title}
                        className="input"
                        onChange={(e) => setNewEvent({ ...newEvent, title: e.target.value })}
                        type="text"
                        id="task"
                        placeholder="Enter your task"
                        required
                    />
                    <div className="datetime-container">
                        <div className="date-input">
                            <label htmlFor="start-date">Start Date:</label>
                            <DatePicker
                                selected={newEvent.start}
                                onChange={(date) => setNewEvent({ ...newEvent, start: date })}
                                dateFormat="MM/dd/yyyy"
                                placeholderText="Start Date"
                                className="input"
                                required
                            />
                        </div>
                        <div className="time-input">
                            <label htmlFor="start-time">Start Time:</label>
                            <input
                                type="time"
                                id="start-time"
                                value={newEvent.start ? moment(newEvent.start).format('HH:mm') : ''}
                                onChange={(e) => {
                                    const startTime = moment(newEvent.start).set({
                                        hour: e.target.value.split(':')[0],
                                        minute: e.target.value.split(':')[1],
                                    });
                                    setNewEvent({ ...newEvent, start: startTime });
                                }}
                            />
                        </div>
                    </div>
                    <div className="datetime-container">
                        <div className="date-input">
                            <label htmlFor="end-date">End Date:</label>
                            <DatePicker
                                selected={newEvent.end}
                                onChange={(date) => setNewEvent({ ...newEvent, end: date })}
                                dateFormat="MM/dd/yyyy"
                                placeholderText="End Date"
                                className="input"
                                required
                            />
                        </div>
                        <div className="time-input">
                            <label htmlFor="end-time">End Time:</label>
                            <input
                                type="time"
                                id="end-time"
                                value={newEvent.end ? moment(newEvent.end).format('HH:mm') : ''}
                                onChange={(e) => {
                                    const endTime = moment(newEvent.end).set({
                                        hour: e.target.value.split(':')[0],
                                        minute: e.target.value.split(':')[1],
                                    });
                                    setNewEvent({ ...newEvent, end: endTime });
                                }}
                            />
                        </div>
                    </div>
                    <button onClick={handleAddEvent} className="submit">
                        Add Event
                    </button>
                </form>
            </div>
            <Calendar
                localizer={localizer}
                events={allEvents}
                startAccessor="start"
                endAccessor="end"
                style={{ height: 500, margin: '50px' }}
                selectable={true}
                onSelectSlot={handleSelectSlot}
            />


        </div>
    );
};

export default Post;
