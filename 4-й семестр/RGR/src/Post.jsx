import React, { useState, useEffect } from 'react';
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
    const [selectedEvent, setSelectedEvent] = useState(null);

    useEffect(() => {
        const savedEvents = localStorage.getItem('events');
        if (savedEvents) {
            setAllEvents(JSON.parse(savedEvents));
        }
    }, []);

    useEffect(() => {
        localStorage.setItem('events', JSON.stringify(allEvents));
    }, [allEvents]);


    const handleAddEvent = () => {
        if (!newEvent.title || !newEvent.start || !newEvent.end) {
            alert('Please enter all fields');
            return;
        }

        const updatedEvents = [...allEvents, { ...newEvent, id: Date.now() }];
        setAllEvents(updatedEvents);
        setNewEvent({ title: '', start: null, end: null });
    };

    const handleDeleteEvent = () => {
        if (!selectedEvent) {
            alert('Please select an event');
            return;
        }

        const updatedEvents = allEvents.filter((event) => event.id !== selectedEvent.id);

        setAllEvents(updatedEvents);
        setSelectedEvent(null);
    };

    const handleSelectSlot = (slotInfo) => {
        const start = slotInfo.start;
        const end = slotInfo.end;

        setNewEvent({ ...newEvent, start, end });
        setSelectedEvent(null);
    };

    const handleSelectEvent = (event) => {
        setSelectedEvent(event);
        setNewEvent({
            title: event.title,
            start: moment(event.start).toDate(),
            end: moment(event.end).toDate()
        });
    };

    const handleStartTimeChange = (e) => {
        if (newEvent.start) {
            const startTime = moment(newEvent.start).set({
                hour: e.target.value.split(':')[0],
                minute: e.target.value.split(':')[1],
            });
            setNewEvent({ ...newEvent, start: startTime });
        }
    };

    const handleEndTimeChange = (e) => {
        if (newEvent.end) {
            const endTime = moment(newEvent.end).set({
                hour: e.target.value.split(':')[0],
                minute: e.target.value.split(':')[1],
            });
            setNewEvent({ ...newEvent, end: endTime });
        }
    };




    return (
        <div className="App">
            <h1>Calendar</h1>
            <h2>Add/Edit Event</h2>
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
                                calendarClassName="custom-datepicker"
                            />
                        </div>
                        <div className="time-input">
                            <label htmlFor="start-time">Start Time:</label>
                            <input
                                type="time"
                                id="start-time"
                                value={newEvent.start ? moment(newEvent.start).format('HH:mm') : ''}
                                onChange={handleStartTimeChange}
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
                                calendarClassName="custom-datepicker"
                            />
                        </div>
                        <div className="time-input">
                            <label htmlFor="end-time">End Time:</label>
                            <input
                                type="time"
                                id="end-time"
                                value={newEvent.end ? moment(newEvent.end).format('HH:mm') : ''}
                                onChange={handleEndTimeChange}
                            />
                        </div>
                    </div>
                    {selectedEvent ? (
                        <div className="button-container">
                            <button onClick={handleDeleteEvent} className="submit delete">
                                Delete Event
                            </button>
                        </div>
                    ) : (
                        <button onClick={handleAddEvent} className="submit">
                            Add Event
                        </button>
                    )}
                </form>
            </div>
            <div className="calendar-container" style={{ marginTop: '220px' }}>
                <Calendar
                    localizer={localizer}
                    events={allEvents}
                    startAccessor="start"
                    endAccessor="end"
                    style={{ height: '100%' }}
                    selectable
                    onSelectSlot={handleSelectSlot}
                    onSelectEvent={handleSelectEvent}
                />
            </div>


        </div>
    );
};

export default Post;
